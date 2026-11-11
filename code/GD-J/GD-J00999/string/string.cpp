#include<bits/stdc++.h>
using namespace std;
struct zz{
	int z;
	char c;
};
int l=0,a1[30],a2[30];
zz b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i].z;
		l+=b[i].z;
		cin>>b[i].c;
	} 
	int qqq=0;
	int s=0;
	int a1s=0;
	l/=2;
	l++;
	for(int i=0;i<n;i++){
		qqq+=b[i].z;
		if(qqq<l){
			a1[int(b[i].c-'a')]+=b[i].z;
			a1s+=b[i].z;
		}else if(qqq>=l){
			if(s==0){
				a1[int(b[i].c-'a')]+=l-a1s;
				a2[int(b[i].c-'a')]+=qqq-l-1;
				s=1;
			}
			a2[int(b[i].c-'a')]+=b[i].z;
		}
	} 
	int cy=0;
	for(int i=0;i<26;i++){
		cy+=max(a1[i],a2[i])-min(a1[i],a2[i]);
	} 
	cout<<cy;
	return 0;
} 
