#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
        int num;
        char id;
        cin >> num >> id;
        while(num--)
            a+=id;
	}
    long long cnt=0,b=a.size();
    for(int i=0;i<=b/2;i++){
        if(a[i]!=a[b-i-1])
            cnt++;
    }
    if(b%2==0)    cnt--;
    cout << cnt;
	return 0;
}
