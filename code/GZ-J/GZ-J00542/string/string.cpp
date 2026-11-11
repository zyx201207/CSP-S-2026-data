//GZ-J00542 张季萌 同为京学附属实验学校
#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],im=0,num=0,l;
char c[1000000];
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s[im]=c[i];
			im++;
		}
	}
	l=s.size();
	int inm=0;
	if(l%2==0){
		l=l/2;
		for(int i=0;i<l;i++){
			s1[i]=s[i];
		}
		for(int i=l;i<n;i++){
			s2[inm]=s[i];
			inm++;
		}
	}
	else{
		l=l/2;
		for(int i=0;i<l;i++){
			s1[i]=s[i];
		}
		for(int i=n;i>l-1;i--){
			s2[inm]=s[i];
			inm++;
		}
	}
	for(int i=0;i<l;i++){
		if(s1[i]!=s2[i]){
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
