#include <bits/stdc++.h>
using namespace std;
long long arr[1000086],crr[1000086];
string s;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for ( long long i = 0 ; i < n ; i++ ){
		cin>>arr[i];
	}
	for ( long long i = 0 ; i < n ; i++ ){
		s = "";
		for ( long long j = i ; j < n ; j++ ){
			long long t = s.find(arr[j] + '0');
			cout<<t<<" "<<char(arr[j] + '0')<<endl;
			if(t == -1){
				s = s + char(arr[j] + '0');
				continue;
			}
			else{
				for ( long long r = t ; r <= j ; r++){
					s[r] = '0';
				}
			}
			s = s + char(arr[j] + '0');
		}
		for ( long long i = 0 ; i < s.size() ; i++ ){
			crr[s[i] - '0']++; 
		}
		cout<<s<<endl;
	}
	for ( long long i = 1 ; i <= m; i++)cout<<crr[i]<<" ";
	return 0;
} 
