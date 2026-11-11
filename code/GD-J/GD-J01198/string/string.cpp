#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}str[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&str[i].a);
		cin>>str[i].c;
	}
	int i=1,j=n;
	long long sum=0;
	while(i<j){
		if(str[i].c!=str[j].c){
			sum+=min(str[i].a,str[j].a);
		}
		if(str[i].a<str[j].a){
			str[j].a-=str[i].a;
			i++;
		}
		else if(str[i].a>str[j].a){
			str[i].a-=str[j].a;
			j--;
		}
		else{
			i++,j--;
		}
	}
	printf("%lld",sum);
	return 0;
}
