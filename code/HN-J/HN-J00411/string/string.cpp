#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int o=1;o<=a;o++){
			s+=c;
		}
		sum+=a;
	}
	int a,b,ans=0;
	if(sum%2==0){
		a=sum/2-1;
		b=a+1;
	}else{
		a=sum/2+1;
		b=a;
	}
	a-=1;
	b-=1;
	while(1){
		if(s[a]!=s[b])ans++;
		if(a==0)break;
		a--;
		b++;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
