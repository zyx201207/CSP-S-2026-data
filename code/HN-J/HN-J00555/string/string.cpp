#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
char c;
string s=" ";
long long k=0;
void spa(long long a,char c){
	for(long long l=0;l<a;l++){
			s[k++]=c;	
			k++;
	} 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		spa(a,c);
	}
	long long mid=(0+k-1)/2;
	long long l=mid-1,r=mid+1;
	long long ans=0;
	for(int i=0;i<k/2;i++){
		if(s[l]!=s[r]){
			ans++;
		}
		l--;
		r++;
	}
	cout<<ans;
	return 0;
}
