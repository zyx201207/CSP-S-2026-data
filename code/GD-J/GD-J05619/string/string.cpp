#include<bits/stdc++.h>
using namespace std;
long long c,he=0,sum=0;
struct hv{
	long long shu;
	char zm;
	};
hv a[10086];
long long an(){
	long long l=1,r=c;
	while(l<r){
		if(a[l].zm!=a[r].zm){
			sum++;	
		}
		a[l].shu--;
		a[r].shu--;
		if(a[l].shu==0){
			l++;
		}
		if(a[r].shu==0){
			r--;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>c;
	for(long long i=1;i<=c;i++){
		cin>>a[i].shu;
		he+=a[i].shu;
		cin>>a[i].zm;
	}
	if(he%2==0){
		cout<<an();
	} else{
		cout<<an();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
