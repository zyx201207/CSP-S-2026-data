//GZ-J00541 兴义市弘毅中学 刘桐瑞
#include<bits/stdc++.h>
using namespace std;
long long n,l,L,z1,h;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>a;
		L+=l;

		for(int j=0;j<l;j++){
			s+=a;
		}
}
L=s.size();
if(L%2==0){
	z1=L/2-1;
	for(int i=0;i<=z1;i++){
		if(s[i]!=s[L-i-1]){
			h++;
		}
	}	
	
}else{
z1=L/2;
for(int i=0;i<z1;i++){
		if(s[i]!=s[L-i-1]){
			h++;
		}
	}	
}
cout<<ans<<'\n';
	return 0;
} 
