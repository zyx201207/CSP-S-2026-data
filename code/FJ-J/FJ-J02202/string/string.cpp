#include<bits/stdc++.h>
using namespace std;
long long a,n,x=0,y=0;
string s,c;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
cin>>n;
for(int i=0;i<n;i++){
	cin>>a>>c;
	for(int j=0;j<a;j++){
	s+=c;
}
}

for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i]){
			x++;
		}
		y++;

}
if(y==(s.size()+1)/2){
		cout<<0;
		return 0;
	}
	else {
		cout<<x;
	}
	return 0;
}

