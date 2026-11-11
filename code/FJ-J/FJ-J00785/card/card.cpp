#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a+1],s[b+1];
	for(int i=1;i<=b;i++)s[i]=0;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		int mian[b+1],l=0;
		for(int j=i+1;j<=a;j++){
			for(int t=1;t<=l;t++){
				if(mian[t]==c[j]){
					for(int t1=t;t1<=l;t1++){
						mian[t1]=0;
						l--;
					}
				}
			}
			mian[l]=c[j];
			l++;
		}
		for(int j=1;j<=l;j++)s[mian[j]]++;
		
	}
	for(int i=1;i<=b;i++)cout<<s[i]<<' ';
	return 0;
}

