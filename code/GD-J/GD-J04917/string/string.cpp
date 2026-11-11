#include<bits/stdc++.h>
using namespace std;
long long n,num[208200],cnt;
char ch[208200];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cin>>ch[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(ch[l]!=ch[r]){
			if(num[l]>num[r]){
				num[l]-=num[r];
				cnt+=num[r];
				r--;
			}
			else if(num[l]<num[r]){
				num[r]-=num[l];
				cnt+=num[l];
				l++;
			}
			else{
				cnt+=num[l];
				l++;
				r--;
			}
		}
		else{
			l++;
			r--;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
