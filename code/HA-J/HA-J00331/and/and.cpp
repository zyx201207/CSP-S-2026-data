#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long MAXn=1000000000000000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	unsigned long long a,b,c[MAXn],ans[MAXn],t=0;
	c[0]=0,ans[0]=MAXn;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(c[j]>c[t]&&c[ans[i-1]]>c[i]){
				t=j;
			}
		}	
		ans[i]=t;
		t=0;
	}
	cout<<c[ans[b]];
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
