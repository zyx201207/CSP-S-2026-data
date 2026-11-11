#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[300005],c[300005],ch,d[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]+=i;
		c[a[i]]++;
		if(c[a[i]]>1){
			ch++;
		}
	}
	long long l=0;
	for (int i=1;i<=n-1 ;i++){
		l=i;
		//if(ch!=0){
			//int ch1=ch;
			//if(c[a[i]]>1){
				//ch--;
			//}
			for (int j=i;j<=n;j++){
				//if(ch1==0)break;
				if(d[a[j]]){
					//ch1--;
					for (int k=d[a[j]];k<=j-1;k++){
						if(d[a[k]]!=0){
							b[a[k]]--;
						}
						d[a[k]]=0;
					}
					
				}
				d[a[j]]=j;
			}
		}
	//}
	for (int i=1;i<=m;i++){
		cout<< b[i] <<" ";
	}
	return 0;
} 
