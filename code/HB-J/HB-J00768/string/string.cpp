#include<bits/stdc++.h>
using namespace std;
struct sss{
	int num;
	char zm;
} a[200100];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ab;
	cin>>ab;
	for(int i=0;i<ab;i++){
		scanf("%d %c",&a[i].num,&a[i].zm);
	}
	int x=0,y=ab-1;
	while(x<y){
		long long add=1ll*(a[x].num<a[y].num?a[x].num:a[y].num);
		if(a[x].zm!=a[y].zm){
			ans+=1ll*add;
		}
		a[x].num-=add;
		a[y].num-=add;
		if(a[x].num==0){
			x++;
		}
		if(a[y].num==0){
			y--;
		}
	}
	cout<<ans;
	return 0;
}
