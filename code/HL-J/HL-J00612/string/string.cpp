#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	scanf("%d",&n);
	int a1[200001]={};
	char a2[200001]={};
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a1[i];j++){
		    a+=a2[i];
		}
	}
	int len=a.length();
	int ans=0;
	for(int i=0;i<len/2;i++){
		if(a[i]!=a[len-i-1]){
			ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout); 
    return 0;
}

