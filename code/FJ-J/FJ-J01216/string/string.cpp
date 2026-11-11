#include <bits/stdc++.h>
using namespace std;

struct st{
	int a;
	char c;
};


int n;
unsigned long long num;
st arr[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	
	int len = 0;
	for(int i=1;i<=n;i++){
		cin >> arr[i].a >> arr[i].c;
		len += arr[i].a;
	}
	
	int l = 1,r = n;
	
	for(int i=1;l<r;i++){
		if(arr[l].c!=arr[r].c){
			num += min(arr[l].a,arr[r].a);
		}
		
		if(arr[l].a<arr[r].a){
			arr[r].a -= arr[l].a;
			arr[l].a = 0;
			l++;
		}else if(arr[l].a>arr[r].a){
			arr[l].a -= arr[r].a;
			arr[r].a = 0;
			r--;
		}else{
			arr[l].a = arr[r].a = 0;
			l++;
			r--;
		}
	}
	
	cout << num;
	
	return 0;
}
