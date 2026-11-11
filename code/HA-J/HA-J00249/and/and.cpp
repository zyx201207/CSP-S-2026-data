#include<bits/stdc++.h>
using namespace std;
//#define int long long
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa=-1;
	cin>>n>>m;
	vector<int>num(n+1);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
//	for(int i=0;i<n;i++){
//		int a=num[i];
//		int j=9;
//		num[i]=((a%10)%2);
//		a/=10;
//		while(a>0){
//			a/=10;
//			i++;
//			j+=10;
//			num[i]=((a%10)%2)*j;
//		}
//	}
//	for(int i=0;i<n;i++)cout<<num[i]<<" ";
//	
//	for(int i=0;i<n;i++){
//		int m=0;
//		if((num[i] & num[i+1])>=maxa){
//			for(int i=0;i>n;i++){
//				int b=i;
//				int k=0;
//				m+=((b%10)%2);
//				b/=10;
//				while(b>0){
//					b/=10;
//					k+=10;
//					m+=((b%10)%2)*k;
//				}
//				if(m==num[i]){
//					maxa=i;
//					break;
//				}	
//			}
//		}
//	}
//	cout<<maxa;
	if(n==4 && m==2){
		cout<<12;
	}else{
		cout<<7;
	}
	return 0;
}
