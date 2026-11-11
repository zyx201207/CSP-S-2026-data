#include <iostream>

using namespace std;

int main(){
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	int n;
	long long sum=0 ,ans=0 ,j=1 ,p=1;
	int a[200005];
	char c[200005];
	cin >> n;
	for(int i=1; i<=n; i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
	}
	p=n;
	for(int i=1; i<=sum/2; i++){
        if(c[j]!=c[p]){
            ans++;
        }
        a[j]--;
        a[p]--;
        if(a[j]==0){
            j++;
        }
        if(a[p]==0){
            p--;
        }
	}
    cout << ans << endl;
	return 0;
}
