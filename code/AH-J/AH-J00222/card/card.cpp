#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int f[500005];
int y[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[a[i]]++;
	int flag=0;
	int id=0;
	for(int i=1;i<=n;i++){
		y[a[i]]++;
		cout<<flag<<" "<<f[a[i]]<<" "<<y[a[i]]<<endl;
		if(flag==0&&f[a[i]]==1){
			cnt[a[i]]+=i;
			f[a[i]]--;
			if(y[a[i]]!=1)
				flag--;
		}	
		else if(flag==1&&f[a[i]]==1&&y[a[i]]==1){
			cnt[a[i]]+=i-id;
			if(y[a[i]]!=1)
				flag--;
		}
		else if(flag==1&&f[a[i]]==1&&y[a[i]]>1){
			cnt[a[i]]+=i;
			if(y[a[i]]!=1)
				flag--;
		}
		else{
			id=i;
			f[a[i]]--;
			if(y[a[i]]==1)
				flag++;
		}
			
		
	}
	//cout<<endl;
	for(int i=1;i<m;i++)
		cout<<cnt[i]<<" ";
	cout<<cnt[m];
	return 0;
} 


/*

4 3
1 2 1 3

*/
