#include<bits/stdc++.h>
using namespace std;
/*string hlt(string s,int a,char b){
	if(a>0){
		s+=b;
		a--;
		return hlt(s,a,b);
	}else{
		return s;
	}
}*/
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={};
	char s1[n]={};
	long long sum=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	    scanf("%s",&s1[i]);
	    sum+=a[i];
	}
    char s[sum]={};
    //string s="";
	int j=0;
	for(int i=0;i<sum;i++){
		/*s=hlt(s,a[j],s1[j]);*/
		while(a[j]>0){
			s[i]=s1[j];
			a[j]--;
		}
		j++;
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-1-i]){
			ans++;
		}
	}
	printf("%lld",ans); 
	return 0;
}
