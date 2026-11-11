#include<bits/stdc++.h>
using namespace std;
string s;
int a[201000];
char b[201000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int cnt=0;
	int k=0; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt+=a[i];
		scanf(" %s",&b[i]);
		for(int j=1;j<=a[i];j++){
			k++;
			s[k]=b[i];
		}
	}
	
	int ans=0;
	
	if(cnt%2==1){
		int mid=(cnt+1)/2;
		
		for(int i=1;i<mid;i++){
			if(s[i]!=s[cnt]){
				ans++;
			}
			cnt--;
		}
		cout<<cnt;
		return 0;
	}
	
	return 0;
} 
