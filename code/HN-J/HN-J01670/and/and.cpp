#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e5+10;

int n,m,x,old[N],a[N][31],len,cnt[31],ans,sum;
bool b[N];

bool cmp(const int &A,const int &B){
	return A>B;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>old[i];
	sort(old+1,old+n+1,cmp);
	for(int i=1;i<=n;i++){
		x=old[i],len=0;
		while(x)
			a[i][++len]=x%2,x/=2;
	}
	for(int i=1;i<=30;i++)
		for(int j=1;j<=n;j++)
			cnt[i]+=a[j][i];
	for(int i=1;i<=30;i++)
		if(cnt[i]>=m){
			int tot=0; 
			for(int j=1;j<=n;j++)
				if(a[j][i])
					b[j]=true,tot++;
				else
					if(!a[j][i])
						b[j]=false;
		}
	bool flag=true;
	int tot=0;
	for(int i=1;i<=n;i++)
		if(b[i]&&tot<=m){
			if(flag)
				ans=old[i],flag=false;
			else
				ans&=old[i];
			tot++;
		}
	cout<<ans;
}
