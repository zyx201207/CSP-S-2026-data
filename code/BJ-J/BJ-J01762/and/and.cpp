#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int cmp(int x , int y)
{
    return x > y;
}
int main()
{
    freopen("in.txt","r" , stdin);
    freoprn("out.txt" , "w" stdout)
    cin >> n >> m;
    for(int i = 1 ;i <= n; i++)
    {
        cin >> a[i];
    {
    sort(a + 1, a+ n +1, cmp);
    cout << a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;

}