#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int n;
long long int m, c_m;
vector<long long int> a, c_a;
long long int
currOper,
tmpCurMax,
tmpSum,
maxDepth = -INF;
;
vector<long long> usedIndexes;
vector<long long int> lOper;
bool specA;
bool funcComp(long long int a, long long int b)
{
    if (b < a) return true;
    else return false;
}
void searchFunc(long long index, long long depth, long long stepsLeft)
{

    // if (index % 30 == 0)
    if (false)
    //nif (max(maxDepth, depth) - maxDepth > 0)
    {
        // cout << index << endl;
        printf("searchFunc: lOper[%lld]=%lld depth=%lld, %lld step(s) left\n", index, lOper[index], depth, stepsLeft);
        cout << "maxDepth=" << maxDepth << endl;
        // cout << tmpCurMax << " " << a[index + 1] << endl;
        cout << endl;
    }
    stepsLeft -= lOper[index];

    // stepsLeft -= tmpCurMax - a[index + 1];
    if (stepsLeft < 0) return;
    if (max(maxDepth, depth) - maxDepth > 0)
    //    cout << "maxDepth=" << maxDepth << endl;
    maxDepth = max(maxDepth, depth);
    usedIndexes.push_back(index);
    for (int i = index + 1; i < lOper.size(); i++)
    {
        // if (find(usedIndexes.begin(), usedIndexes.end(), i) != usedIndexes.end())
        {
            // break;
        }
        searchFunc(i, depth + 1, stepsLeft);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    // freopen("crystal2.in", "r", stdin);
    // freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    /* !!! */
    a.push_back(-INF);
    for (int i = 1; i <= n; i++)
    {
        cin >> currOper;
        a.push_back(currOper);
    }
    a.push_back(INF);

    for (int i = 1; i <= 100; i++)
    {
        if (a[i] == i) specA = true;
        else
        {
            specA = false;
            break;
        }
    }
    if (specA)
    {
        for (int i = 1; i <= sqrt(m); i++)
        {
            currOper = i * (i + 1) / 2;
            if (m >= currOper && m <= (i + 1) * (i + 2) / 2)
                maxDepth = i;
        }
    }
    // cout << n << " " << m << endl;
    sort(a.begin(), a.end() + 1);
    // for (int i = 1; i <= n; i++)
    // {
        // // cout << a[i] << endl;
    // }

    for (int i = n; i >= 1; i--)
    {
        // c_a = a;

        tmpCurMax = a[i];
        // printf("Crystal<%lld>\n", tmpCurMax);
        // // cout << tmpCurMax << endl;
        // tmpSum = 0;
        // c_m = m;
        lOper.clear();
        // vector<long long>().swap(lOper);
        for (int j = 1; j <= i - 1; j++)
        {
            currOper = tmpCurMax - a[j];
            // c_m -= currOper;
            // printf("Crystal<%lld> -> %lld Operation(s)\n",
            //       a[j], currOper);
            // // printf("%lld more step(s). \n", c_m);
            lOper.push_back(currOper);

            if (currOper > m)
            {
                // printf("(because m = %lld ...)\n", m);
                break;
            }
        }
        // sort(lOper.begin(), lOper.end() + 1);
        // cout << endl;
        // for (int j = 0; j < lOper.size(); j++)
        {
            // cout << lOper[j] << endl;
        }

        // cout << endl;
        for (int j = 0; j < lOper.size(); j++)
            searchFunc(j, 0, m);
        // searchFunc(0, 0, m);
    }

    cout << maxDepth + 2;
    return 0;
}
