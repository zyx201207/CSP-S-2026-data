#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in.txt", "r", stdin);
    freopen("card.out.txt", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long arr[n], count1[m] = {0};
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        vector <long long> temp;
        for(int j = i; j < n; j++)
        {
            int count2 = -1;
            for(int k = 0; k < temp.size(); k++)
            {
                if(temp[k] == arr[j])
                {
                    count2 = k;
                    break;
                }
            }
            if(count2 == -1)
                temp.push_back(arr[j]);
            else
                temp.erase(temp.begin() + count2 + 1, temp.end());
        }
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < temp.size(); k++)
            {
                if(temp[k] == j + 1)
                {
                    count1[j] += 1;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
        cout << count1[i] << ' ';
    return 0;
}
