#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
long long c[200100];
char l[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c[i];
		cin>>l[i];
	}
	int left1=c[0],right1=c[n-1],xy1=0,xy2=0;
	char left2=l[0],right2=l[n-1];
	while(n-1-xy2>0+xy1){
		if(left1>=right1){
			if(left2==right2){
				left1-=right1;
				right1=0;
			}
			else{
				sum+=right1;
				left1-=right1;
				right1=0;
			}
		}
		else if(left1<right1){
			if(left2==right2){
				right1-=left1;
				left1=0;
			}
			else{
				sum+=left1;
				right1-=left1;
				left1=0;
			}
		}
		if(left1==0){
			xy1++;
			left1=c[0+xy1];
			left2=l[0+xy1];
		}
		if(right1==0){
			xy2++;
			right1=c[n-1-xy2];
			right2=l[n-1-xy2];
		}
	}
	cout<<sum;
	return 0;
}

