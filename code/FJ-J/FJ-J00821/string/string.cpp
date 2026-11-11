#include <bits/stdc++.h>
#define int long long
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
using namespace std;

struct Thing{
	int a;
	char c;
}t[200010];
int n,m,fi,fj,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t[i].a >> t[i].c;
		m+=t[i].a;
	}
	for(int i=1,sum=0;i<=n;i++){
		if((sum+t[i].a)>(m/2)){
			if((sum+t[i].a-(m+1)/2)>=(m/2-sum)){
				t[i].a=(sum+t[i].a-(m+1)/2)-(m/2-sum);//后减前 
				fi=i-1;
				fj=i;
			}else{
				t[i].a=(m/2-sum)-(sum+t[i].a-(m+1)/2);//前减后 
				fi=i;
				fj=i+1;
			}
			break;
		}
		sum+=t[i].a;
	}
	for(int i=fi,j=fj;i>=1 && j<=n;){
		if(t[i].c!=t[j].c){
			if(t[i].a>=t[j].a){
				ans+=t[j].a;
				t[i].a-=t[j].a;
				j++;
			}else{
				ans+=t[i].a;
				t[j].a-=t[i].a;
				i--;
			}
		}else{
			if(t[i].a>=t[j].a){
				t[i].a-=t[j].a;
				j++;
			}else{
				t[j].a-=t[i].a;
				i--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
