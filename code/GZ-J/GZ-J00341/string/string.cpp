//GZ-J00341 遵义市第四初级中学 彭钰尧
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	string s;
	int n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
	}
	int sum=0;
	int l=s.size();
	string s1,s2;
	for(int i=0;i<l/2;i++){
		s1=s1+s[i];
	}
	for(int i=l-1;i>l-l/2;i++){
		s2=s2+s[i];
	}
	for(int i=0;i<l/2;i++){
		if(s1[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

