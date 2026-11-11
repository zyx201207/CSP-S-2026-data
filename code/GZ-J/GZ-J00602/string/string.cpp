//GZ-J00602 遵义市第四初级中学  彭紫宸 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n;
cin>>n;
int a;
char c;
string s1[n+5];
string s2[n+5];
int sum=0;
for(int i=1;i<=n;i++){
	cin>>a>>c;
	sum=sum+a;
	for(int j=0;j<=a;j++){
	s1[j]=c;
	}
	for(int k=a;k>=0;k--){
	s2[k]=c;
	}
}

int up=0;	
for(int i=0;i<=sum;i++){
if(s1[i]!=s2[i]){
	up=1;
}
}
if(up==0){
	cout<<"0";
}
}
