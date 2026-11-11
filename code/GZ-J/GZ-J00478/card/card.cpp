//GZ-J00478 遵义航天高级中学 张煜皓
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+4;
int n,m,len;
int a[N];
int desktop[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);//别看了，乱写的………… 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int ju=0;ju<n;ju++){
		for(int i=ju;i<n;i++){
			int find=0;
			for(int j=0;j<len;j++){
				if(a[j]==a[i]){
					find=j;
					break;
				}
			}
			if(find){
				len=find;
			}
			desktop[len]=a[i];
			len++;
		}
		for(int i=0;i<len;i++){
			cout<<desktop[i]<<' ';
			ans[desktop[i]]++;
		}cout<<endl;
		for(int i=0;i<n;i++){
			desktop[i]=0;
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

