#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int N=2e6+10; 
const ll inf=(ll)4e18+4LL;

int c,t,n;
int r_max[N],l_max[N],r_num[N],l_num[N],l_to[N],r_to[N];
ll pos[N],d;

void test(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>pos[i];
	pos[n+1]=inf,pos[0]=-inf;
	int now_it=1;
	for(int i=1;i<=n;i++){
		while(pos[now_it]-pos[i]<=d)	now_it++;
		r_max[i]=now_it-1;
	}
	now_it=n;
	for(int i=n;i>=1;i--){
		while(pos[i]-pos[now_it]<=d)	now_it--;
		l_max[i]=now_it+1;
	}
	for(int i=1;i<=n;i++)	l_to[i]=r_to[i]=l_num[i]=r_num[i]=0;
	for(int i=1;i<=n;i++)
		if(r_max[i]!=i)
			if(i==l_max[r_max[i]])	l_num[r_max[i]]=l_num[i]+1;
	for(int i=n;i>=1;i--)
		if(l_max[i]!=i)
			if(i==r_max[l_max[i]])	r_num[l_max[i]]=r_num[i]+1;
	for(int i=1;i<=n;i++)	if(r_max[i]!=i)	l_to[r_max[i]]++;
	for(int i=n;i>=1;i--)	if(l_max[i]!=i)	r_to[l_max[i]]++;
	ll ans=0;
	for(int i=1;i<n;i++){
		int p2=i,p3=i+1,p1=l_max[p2];
		if(p1==p2)	continue;
		if(r_max[p1]==p3&&l_max[p3]==p1)	ans+=1LL*l_num[p1]*r_to[p2];
	}
	for(int i=n;i>1;i--){
		int p3=i,p2=i-1,p4=r_max[p3];
		if(p4==p3)	continue;
		if(r_max[p2]==p4&&l_max[p4]==p2)	ans+=1LL*r_num[p4]*l_to[p3];
	}
	for(int i=1;i<n;i++){
		int p2=i,p3=i+1,p1=l_max[p2],p4=r_max[p3];
		if(p4==p3||p1==p2)	continue;
		if(l_max[p3]==p1&&r_max[p1]==p3&&l_max[p4]==p2&&r_max[p2]==p4)	ans+=1LL*l_num[p1]*r_num[p4];
	}
	for(int i=1;i<n;i++)
		if(l_max[i+1]!=i&&r_max[i]!=i+1)
			ans+=1LL*l_to[i+1]*r_to[i];
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	
	cin>>c>>t;
	while(t--)	test(); 
	
	return 0;
} 
