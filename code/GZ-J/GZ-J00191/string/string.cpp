//¿ÓÓ£ª∏  GZ-J00191 
#include <bits/stdc++.h>
using namespace std;
const int N =1e5+10;
long long a[N],n,num,cnt = 0;
char c[N];
long long s1,s2;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin >> n;
	a[0] = 0;
	s1 = 1,s2 = n;
	for(long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	for(long long i = 1,j = a[n];;){
		if(i>a[s1]) s1++,i = 1;
		if(j<1) s2--,j = a[s2];
		if(c[s1]!=c[s2]){
			cnt++;
		}
		if(s1+1==s2){
			if(i==a[s1]&&j==1) break;
		}
		if(s1==s2&&((i+1==j)||(i+2==j)||(i==j))){
			break;
		}
		i++,j--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
