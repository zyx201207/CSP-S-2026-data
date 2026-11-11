#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n; 
int ans;
int len;
int res;
int a[N];
char ch[N]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		len+=a[i];
	}
	res=n;
	for(int i=1,last=n;i<=n;i++){
		if(a[i]==0&&res<=1){
			break;
			cout<<1;
		}
		if(n+1-i<i&&res<=1){
			break;
			cout<<1;
		}
		int j=i;
		while(a[i]>0){
			if(last<i){ 
				break;
			}
			if(ch[i]!=ch[last]){
				if(a[i]>a[last]){
					ans+=a[last];
					a[i]-=a[last];
					a[last]=0;
					res--;
					last--;
				}else{
					ans+=a[i];
					a[last]-=a[i];
					a[i]=0;
					res--;
				}
			}else{
				if(a[i]>a[last]){
					a[i]-=a[last];
					a[last]=0;
					res--;
					last--;
				}else{
					a[last]-=a[i];
					a[i]=0;
					res--;
				}
			}
//			cout<<a[i]<<' ';
			j++;
		}
	}
	cout<<ans;
	return 0;
}
//这个出题人是真tm的毒瘤
//我 f*ck出题人
//f*ck ccf 
//abababababab
//我常常追忆过去，生命瞬间定格在脑海，所以我死了。 
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++ 
//希望上迷惑行为大赏 
