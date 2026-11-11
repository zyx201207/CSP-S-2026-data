#include<bits/stdc++.h>
using namespace std;
struct node{
	long long m1;
	char s1;
}a1[200010];
struct node1{
	long long m2;
	char s2;
}a2[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i].m1>>a1[i].s1;
		num+=a1[i].m1;
	}
	num/=2;
	for(int i=1;i<=n;i++){
		if(num-a1[i].m1==0){
			a2[i].m2=a1[i].m1;
			a2[i].s2=a1[i].s1;
			break;
		}
		if(num-a1[i].m1>0){
			num-=a1[i].m1;
			a2[i].m2=a1[i].m1;
			a2[i].s2=a1[i].s1;
		}else{
			a2[i].m2=a1[i].m1-num;
			a2[i].s2=a1[i].s1;
			break;
		}
	}
	long long ans=0,k=1;
	for(int i=n;i>n/2;i--){
		if(a2[k].s2!=a1[i].s1){
			if(a2[k].m2>=a1[i].m1){
				ans+=a1[i].m1;
				a2[k].m2-=a1[i].m1;
			}else if(a2[k].m2<a1[i].m1){
				int f=(a1[i].m1-a2[k].m2);
				ans+=f;
				k++;
		}
		}else if(a2[k].s2==a1[i].s1){
			if(a2[k].m2>a1[i].m1){
				a2[k].m2-=a1[i].m1;
				cout<<-11<<' ';
			}else if(a2[k].m2<=a1[i].m1){
				k++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
