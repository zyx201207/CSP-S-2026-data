#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long cnt;
	char num;
}a[200005];

unsigned long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].cnt>>a[i].num;
	int qwe=0;
	for(int i=1,j=n;i<=j;){
		long long gh=min(a[i].cnt,a[j].cnt);
		//cout<<a[i].cnt<<" "<<a[j].cnt<<" "<<gh<<endl;
		if(a[i].num!=a[j].num)
			ans+=gh;
		a[i].cnt-=gh;
		a[j].cnt-=gh;
		if(a[i].cnt==0)
			i++;
		if(a[j].cnt==0)
			j--;
		if(i==j&&(a[i].cnt==0||a[j].cnt==1))
			break;
		qwe++;
	}
	cout<<ans;
	return 0;
} 

/*

3
2 a
2 b
1 c

*/


