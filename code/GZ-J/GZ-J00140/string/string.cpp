//GZ-J00140，石光轩，观山湖区第九中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l=0;
	int n,m[10005],num;
	string s[10005],t;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>m[i]>>t;
		for(int j=0;j<m[i];j++){
			s[j]=t;
		}
		num+=m[i];
	}
	int num1=num/2;
	int num2=num-num1;
	for(int i=0;i<num1;i++){
		if(s[i]!=s[num2]){
			l+=1;
		}
	}
	cout<<l;
	
}
