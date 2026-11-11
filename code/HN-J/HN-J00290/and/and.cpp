#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000]={},max_ge=0,max_zhong=0;
	char ai[8]={},bj[8]={},ck[8]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] >= max) max=a[i];
	} 
	if(m==1) cout<<max;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int k=0;k<8;k++){
				ai[8-k]=a[i]%2;
			}
			for(int j=i+1;j<n;j++){
				for(int k=1;k<=8;k++){
					bj[8-k]=a[j]%2;
				}
				for(int k=0;k<8;k++){
					if(ai[k]!='0'&&bj[k]!=0){
						ck[k]=1;
					}else{
						ck[k]=0;
					}
				}
			} 
			int sum=(((((ck[0]*2+ck[1])*2+ck[2])*2+ck[3])*2+ck[4])*2+ck[5])*2+ck[6])*2+ck[7];
			if(sum>max_zhong) max_zhomg=sum;
		}
		cout<<sum;
	}
	return 0;
}
