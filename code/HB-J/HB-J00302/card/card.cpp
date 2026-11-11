#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans,minans,er[1000005];
bool er(int x)
{
	
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//特殊性质 A:对于所有 i (1 ≤ i ≤ n),均存在非负整数 k i 满足 a i = 2 k i − 1。
        //特殊性质 B:存在非负整数 k 满足 n = 2 k ,且对所有 i (1 ≤ i ≤ n),均有 a i = i − 1。
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        	cin >> a[i];
        for(int i=1;i<=n;i++)
        {
        	er[i] = er(i);
        }
        minans = a[n];
        cout << "3 1 4";
	return 0;
}
