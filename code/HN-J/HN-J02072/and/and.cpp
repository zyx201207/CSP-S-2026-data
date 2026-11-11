#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[200005],ch[200005],ind;
int ans;
void Try(int need,int now){
	if(need==0){
		int val=ch[0];
		for(int i=1;i<m;i++){
			val=val&ch[i];
		}
//		for(int i=0;i<m;i++){
//			cout<<ch[i]<<" ";
//		}
//		cout<<val<<endl; 
		ans=max(ans,val);
		return;
	}
	for(int i=now+1;i<n;i++){
		ch[ind++]=arr[i];
		Try(need-1,i);
		ind--;
		
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,arr[i]);
		}
		printf("%d",ans);
		return 0;
	}else if(m==n){
		ans=arr[0];
		for(int i=1;i<n;i++){
			ans=ans&arr[i];
		}
		printf("%d",ans);
	}
	Try(m,0);
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
