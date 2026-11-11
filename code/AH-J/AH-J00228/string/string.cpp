#include<bits/stdc++.h>
using namespace std;
char b[200111];
long long dz=1,dz2,n,d=1,a[200111],z;
long long cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	dz2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(dz!=dz2){
		if(b[dz]==b[dz2]){
			if(a[dz]>a[dz2])  {a[dz]-=a[dz2];a[dz2]=0;dz2--;}
			else  {a[dz2]-=a[dz];a[dz]=0;dz++;}
		}else{
			cnt+=min(a[dz2],a[dz]);
			if(a[dz]>a[dz2])  {a[dz]-=a[dz2];a[dz2]=0;dz2--;}
			else  {a[dz2]-=a[dz];a[dz]=0;dz++;}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=1;i<=z/2;i++){
		if(s[i]!=s[z-i+1])  cnt++;
	}*/
	cout<<cnt;
	return 0;
}
