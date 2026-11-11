#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,a[N];
char c[N]; 
struct Node{
	int b,ch;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long x=sum/2,cnt=0,del=0,i=1;
	vector<Node> l,r;
	for(i=1;i<=n;i++){
		if(cnt==x){
			break;
		}
		if(cnt+a[i]>x){
			int ai=x-cnt;
			del=ai;
			l.push_back({ai,c[i]});
			break;
		}
		l.push_back({a[i],c[i]});
		cnt+=a[i];
	}
	a[i]-=del;
	for(;i<=n;i++){
		r.push_back({a[i],c[i]});
	}
	long long ans=0;
	for(int j=0,k=r.size()-1;j<int(l.size());){
		int de=min(l[j].b,r[k].b);
		l[j].b-=de;
		r[k].b-=de;
		if(l[j].ch!=r[k].ch){
			ans+=de;
		}
		if(l[j].b==0) j++;
		if(r[k].b==0) k--;
	}
	cout<<ans<<"\n";
	return 0;
}

