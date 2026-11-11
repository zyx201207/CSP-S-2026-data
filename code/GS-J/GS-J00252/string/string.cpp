#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    long long x;
    char ch;
}a[200005];

int main(){
	
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ch;
	}
	for(int i=1,j=n;;){
        if(i>=j) break;
        if(a[i].ch != a[j].ch){
            ans+=min(a[i].x,a[j].x);
            if(a[i].x>a[j].x){
                a[i].x-=a[j].x;
                j--;
            }
            else if(a[i].x<a[j].x){
                a[j].x-=a[i].x;
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        else{
        	if(a[i].x>a[j].x){
                a[i].x-=a[j].x;
                j--;
            }
            else if(a[i].x<a[j].x){
                a[j].x-=a[i].x;
                i++;
            }
            else {
                i++;
                j--;
            }
		}
	}
	cout<<ans;
	return 0;
}

