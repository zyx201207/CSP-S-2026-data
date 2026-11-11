//GZ-J00069 遵义市新蒲新区滨湖中学 刘李皓阳  
#include<bits/stdc++.h>
using namespace std;
char s[1989000005];
int size;
int huiwen(char a[]){
	long long no = 0;
	for(int i = 0 ; i < size/2 ; i++){
		if(a[i] != a[size - i]) no++;
	}
	if(size%2) no-=1;
	return no;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j = 0;j < a;j++){
			s[size++] = b;
		}
	}
	cout<<huiwen(s);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
