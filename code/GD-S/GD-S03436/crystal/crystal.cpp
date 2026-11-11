#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
long long n,m,ans=1;
long long a[N],s[N];
long long res = 1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//输入 
	cin >> n >> m;
	long long m1=m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n); //升序 
	
	for(int i=n;i>=1;i--){ //从最大的开始
		//i表示所有数尽量加到a[i]项;
		res = 1,m = m1;
		for(int j=i-1;j>=1;j--){
			long long chazhi=a[i]-a[j];
			if(chazhi<=m){
				res++;
				m-=chazhi;
			}else{
				break;
			}
		}
		ans=max(ans,res);
	} 
	
	cout << ans;
	return 0;
}
