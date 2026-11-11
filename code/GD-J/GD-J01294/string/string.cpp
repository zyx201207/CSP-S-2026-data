#include <bits/stdc++.h>
using namespace std;
long long n,al;
long long num[200010],f[200010],l[200010];
char str[200010],fs[200010],ls[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>str[i];
		al+=num[i];
	}
	
	long long fi=1;
	long long half=al/2;
	while(1){
		if(half-num[fi]>0){
			f[fi]=num[fi];
			fs[fi]=str[fi];
			half-=num[fi];
			fi++;
		}else{
			f[fi]=half;
			fs[fi]=str[fi];
			break;
		}
	}
	long long li=1,j=n;
	half=al/2;
	while(1){
		if(half-num[j]>0){
			l[li]=num[j];
			ls[li]=str[j];
			half-=num[j];
			li++;j--;
		}else{
			l[li]=half;
			ls[li]=str[j];
			break;
		}
	}
	
	
	long long i=1;j=1;
	long long sum=0,ans=0;
	while(i<=fi&&j<=li){
		if(f[i]>l[j]){
			if(fs[i]!=ls[j])ans+=l[j];
			j++;
		}else if(f[i]<l[j]){
			if(fs[i]!=ls[j])ans+=f[i];
			i++;
		}else{
			if(fs[i]!=ls[j])ans+=f[i];
			i++;j++;
		}
	}
	cout<<ans;
	return 0;
}
