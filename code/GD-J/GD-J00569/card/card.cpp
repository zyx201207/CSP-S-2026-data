#include<bits/stdc++.h>
using namespace std;
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,len=0;
	cin>>n>>m;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>ans(m+1);
	for(int k=1;k<=n;k++){
		len=0;
		b.clear();
		memset(f,0,sizeof(f));
		for(int i=k;i<=n;i++){
			if(!f[a[i]]){
				//cout<<"b push "<<a[i]<<endl;
				b[++len]=a[i],f[a[i]]=1;
			}
			else{
				int l=0,flag=0;
				for(int j=1;j<=len;j++){
					if(b[j]==a[i]&&!flag){
						l=j;
						flag=1;
						continue;
					}
					if(flag){
						f[b[j]]=0;
					}
				}
				len=l;
				//cout<<"b del "<<a[i]<<" len="<<len<<endl;
			}
		}
		//cout<<k<<" "<<len<<":";
		for(int i=1;i<=m;i++){
			//cout<<b[i]<<" ";
			ans[i]+=f[i];
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
