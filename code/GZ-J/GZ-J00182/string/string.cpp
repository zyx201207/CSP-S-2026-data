//GZ-J00182 北京师范大学贵阳附属中学 赵瀚成 
#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
string c[200010],s="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int l=s.length(),k=0,ans=0;
	if(l%2!=0){
		k=1;
	}
	for(int i=0;i<l;i++){
		cout<<s[i];
	}
	for(int i=0,j=l-1;i<l/2,j>=l/2+k;i++,j--){
		if(s[i]!=s[j]){
			ans=1;
			break;
		}
	}
	if(ans==0){
		cout<<0;
		return 0;
	}
	int s1=0,s2=0;
	for(int i=0,j=l-1;i<l/2,j>=l/2+k;i++,j--){
		if(s[i]!=s[j]){
			s1++;
		}
	}
	for(int i=0,j=l-1;i<l/2,j>=l/2+k;i++,j--){
		if(s[i]!=s[j]){
			s2++;
		}
	}
	cout<<s1<<s2;
	cout<<min(s1,s2);
	return 0;
}
