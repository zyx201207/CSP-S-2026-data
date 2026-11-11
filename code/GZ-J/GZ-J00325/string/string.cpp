//GZ-J00325 遵义航天中学 李银涛 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    long long n,cnt=0;
	cin >> n;
	long long m[n],j=n-1;
	char m1[n];
	for(int i=0;i<n;i++){
		cin >> m[i] >> m1[i];
	}
	for(int i=0;i<n;i){
		if(i>=j){
			cout << cnt;
			return 0;
		}
		if(m1[i]!=m1[j]){
			if(m[i]>=m[j]){
				cnt+=m[j];
			}else{
				cnt+=m[i];
			}
		}
		if(m[i]>=m[j]){
			m[i]-=m[j];
			j--;
		}else{
			m[j]-=m[i];
			i++;
		}
	}
}
