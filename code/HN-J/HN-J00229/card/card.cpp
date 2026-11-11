#include "iostream"
using namespace std;
const int N=5*1e5+5;
int s[N],t[300005],r[300005],h[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		h[i]=s[i];
	}
	int ss=n;
	for(int i=1;i<=ss;i++){
		n=ss;
		for(int j=i;j<=ss;j++){
			s[j]=h[j];
			t[s[j]]=1;
		}
		for(int j=i;j<=ss;j++){
			if(t[h[j]]){
				for(int k=i;k<=n;k++){
					if(s[k]==h[j]){
						for(int p=k;p<=n;p++){
							t[s[p]]=0;
							
						}
						n=k;
						break;
					}
				}
				
			}
			else n++;
			
			
			s[n]=h[j];
			for(int j=i;j<=n;j++){
				t[s[j]]=1;
			}
		/*	for(int i=1;i<=m;i++){
				cout<<t[i]<<' ';
			}
			cout<<endl;*/
			//cout<<n<<'\n';
			for(int j=1;j<=m;j++){
				t[j]=0;
			}
		for(int j=i;j<=n;j++){
		//	cout<<s[j]<<' ';
			t[s[j]]=1;
		}
		//cout<<'\n';
		}
		for(int j=1;j<=m;j++){
			r[j]+=t[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<r[i]<<' ';
	}
	return 0;
}
