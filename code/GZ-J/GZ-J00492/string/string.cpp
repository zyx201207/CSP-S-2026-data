//GZ-J00492 遵义市第十六中学 何世灏 
#include <bits/stdc++.h>
using namespace std;

char t[10000000009];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	long long k=0,p=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%dl",&a);
		cin>>c;
		for(long long j=p;j<a+p;j++){
			t[j]=c;
		}p+=a;
	}long long l=0,r=0;
	if(p%2==0){
		l=p/2-1;
		r=p/2;
	}else l=r=p/2; 
	while(r<=p){
		if(t[l]!=t[r]) k++;
		l--;
		r++;
	}cout<<k;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

