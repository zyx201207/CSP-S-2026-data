
//GZ-J00326 遵义市第19中学 方睿航 
#include <bits/stdc++.h>
using namespace std;
char s[1000000000000000000000000000000000000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long  n,len=0,count=0;
    cin>>n;
    int a[n];
	char c[n];
    for(int i=0;i<n;i++){
    	cin>>a[i]>>c[i];
    	len+=a[i];
	}
	
	len=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[len]=c[i];
			len++;
		}
	}
    int j=len/2; 
    for(int i=0;i<len/2;i++){
    	if(s[i]!=s[j]){
    		count++;
		}
		j--;
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
