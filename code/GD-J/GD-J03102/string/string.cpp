#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt=0,a[200001];
char c[200001];
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
//	for(int i =1;i <= n;i++){
//		int a;
//		char c;
//		cin >> a >> c;
//		for(int i = 1;i <= a;i++){
//			s+=c;
//		}
//	}
//	int i=0,j=s.size()-1;
//	while(i<=j){
//		if(s[i]!=s[j])cnt++;
//		i++;
//		j--;
//	}
//	cout << cnt;
	for(int i =1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int i=1,j=n;
	while(i <= j){
		if(a[i]>a[j]){
			if(c[i] != c[j]){
				a[i]-=a[j];
				cnt+=a[j];
				j--;
			}
			else{
				a[i]-=a[j];
				j--;
			}
		}
		if(a[i]==a[j]){
			if(c[i] != c[j]){
				cnt+=a[j];
				j--;
				i++;
			}
			else{
				j--;
				i++;
			}
		}
		if(a[i]<a[j]){
			if(c[i] != c[j]){
				a[j]-=a[i];
				cnt+=a[i];
				i++;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout << cnt;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a
*/
