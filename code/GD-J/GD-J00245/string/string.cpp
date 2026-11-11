#include<bits/stdc++.h>
using namespace std;
long long num,num_h;
int n,a[200010],h;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		num+=a[i];
	}
	num_h=num;
	for(int i=1;i<=n;i++){
		num-=a[i];
		if(num<num_h/2){
			h=i;
			if(num_h/2-num<num_h/2-(num_h-num-a[i])){
				h++;
			}
			a[i]-=2*min(num_h/2-num,num_h/2-(num_h-num-a[i]));
			if(num_h%2==1){
				a[i]--;
			}
			break;
		}
	}
	num=0;//ÖØ¸´ÀûÓÃ 
	for(int i=h-1;h<=n;){
		if(s[h]!=s[i]){
			num+=min(a[i],a[h]); 
		}
		if(a[h]>=a[i]){
			a[h]-=a[i];
			a[i]=0;
		}
		else{
			a[i]-=a[h];
			a[h]=0;
		}
		if(a[i]<=0){
			i--;
		}
		if(a[h]<=0){
			h++;
		}
	}
	cout<<num;
	return 0;
} 
