//GZ-J00198 遵义市第一初级中学 黄君豪
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int end=0;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
			end++;
		}
	}
	int star=0;
	int sum=0;
	while(star<end){
		if(s[star]!=s[end-1]){
			sum++;
			s[end-1]=s[star];
		}
		star++;
		end--;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

