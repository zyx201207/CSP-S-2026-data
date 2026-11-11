#include <bits/stdc++.h>
using namespace std;
int n,m,a[1145141],b[1145141],book[1145141];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int st=i,end=1,end2=1;
		for(int j=st;j<=n;j++){
			int flag=1;
			
			for(int k=1;k<=end;k++){
				if(flag==0) b[k]=0;
				if(b[k]==a[j]){
					b[k]=0;
					end2=k-1;
					flag=0;
				}
				
			}
			
			b[++end2]=a[j];
			//cout<<end2<<endl;
			end=end2;
		}
		for(int i=1;i<=end;i++){
			//cout<<b[i]<<" ";
			book[b[i]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<book[i]<<endl;
	}
	return 0;
}
