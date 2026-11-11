#include<bits/stdc++.h>
using namespace std;
struct qa{
	int s;
	int x;
	char ch;
};
qa a[20010];
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	int z=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].ch;
		z+=a[i].s;
	}
	int sum=0;
	int k=0;
	if(z%2!=0)k=1;
	int h=1,t=n;
	qa m;
	for(int i=1;i<=n;i++){
		if(z/2>m.s)m.s+=a[i].s;
		else {
			m.x=i;
			break;
		}
	}
	while(h<=m.x-k&&t>=m.x+k){
		if(a[h].ch!=a[t].ch){
			if(a[h].s>a[t].s){
				a[h].s=a[h].s-a[t].s;
				sum+=a[h].s;
				t--;
			}
			else if(a[h].s==a[t].s){
				sum+=a[h].s;
				a[h].s=0;
				a[t].s=0;
				t--;
				h++;
			}
			else {
				a[t].s=a[t].s-a[h].s;
				sum+=a[h].s;
				h++;
			}
		}
			else {
				if(a[h].s>a[t].s){
					a[h].s=a[h].s-a[t].s;
					t--;
			}
				else if(a[h].s==a[t].s){
					a[h].s=0;
					a[t].s=0;
					h++;
					t--;
				}
				else {
					a[t].s=a[t].s-a[h].s;
					h++;
				}
			}
	}
	if(h==m.x){
		if(a[t].ch!=a[h].ch){
			sum+=a[t].s;
		}
	}
	else {
		if(a[t].ch!=a[h].ch){
			sum+=a[t].s;
		}
	}
	cout<<sum;
	return 0;
} 
