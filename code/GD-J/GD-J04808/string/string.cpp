#include<bits/stdc++.h>
using namespace std;
int main(){
//	frepon("string.in",'r',stdin);
//	frepon("string.out",'w',stdout);
	int n,a[100000],l,shi=1,cnt = 0,s[100000];
	string S;
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int i = 1;i<=a[i];i++){
			S+=s[i];
		}
	}
	l = S.size();
	for(int i = 1;i<=(n+1)/2;i++){
		if(a[i] != a[l+1-i]){
			shi = 0;
		}
	}
	if(shi = 1){
		cout<<cnt;
	}
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
