#include <bits/stdc++.h>
using namespace std;
struct node{
	int l;
	char c;
}a[200005];
int n;
long long sum2,sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int left,right;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
		sum+=a[i].l;
	}
	if(sum%2==0){
		for(int i=1;i<=n;i++){
			sum2+=a[i].l;
			if(sum2>=sum/2){
				int y=sum2-sum/2;
				int x=a[i].l-y;
				a[i].l=abs(x-y);
				if(x==y){
					left=i-1;
					right=i+1;
				}else if(x>y){
					left=i;
					right=i+1;
				}else{
					right=i;
					left=i-1;
				} 
				break;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			sum2+=a[i].l;
			if(sum2>sum/2){
				int y=sum2-sum/2-1;
				int x=a[i].l-1-y;
				a[i].l=abs(x-y);
				if(x==y){
					left=i-1;
					right=i+1;
				}else if(x>y){
					left=i;
					right=i+1;
				}else{
					right=i;
					left=i-1;
				} 
				break;
			}
		}
	}
	while(left){
		if(a[left].c==a[right].c){
			int x=a[left].l;
			int y=a[right].l;
			if(x==y){
				left=left-1;
				right=right+1;
			}else if(x>y){
				right++;
				a[left].l-=y;
			}else{
				left--;
				a[right].l-=x;
			} 
		}
		if(a[left].c!=a[right].c){
			int x=a[left].l;
			int y=a[right].l;
			ans+=min(x,y);
			if(x==y){
				left=left-1;
				right=right+1;
			}else if(x>y){
				right++;
				a[left].l-=y;
			}else{
				left--;
				a[right].l-=x;
			} 
		}
	}
	cout<<ans;
	
	return 0;
} 
