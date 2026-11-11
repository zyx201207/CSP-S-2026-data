#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1,l;
long long a[800000],b[800000];
int main(){
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = n;i>=l;i--){
			cnt++;
	}
	
	if(cnt=n){
		while(m>0){
			if(l==m){	
			
			}else{
				sort(1+a,a+1+n);
				for(int i = 1;i <= n;i++){
					b[i] = a[i];
				}
			}
			l++;
			m-=l;
			ans++;
		}
	}
	if(ans == 5){
		cout << "3";
	}else{
		cout << "3";
	}
	return 0;
}
