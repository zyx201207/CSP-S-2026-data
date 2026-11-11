#include<bits/stdc++.h>
using namespace std;

int n = 0 , m = 0 ;
int arr [ 500010 ] ;
bool vis [ 300010 ] ;
map < int , int > bas ;
vector < int > st ;

int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );

    freopen( "card.in" , "r" , stdin );
    freopen( "card.out" , "w" , stdout );

    cin >> n >> m ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr [ i ] ;
    }

    if ( n <= 5050 )
    {
        for ( int i = 1 ; i <= n ; i ++ )
        {
            st.clear () ;
            memset ( vis , 0 , sizeof ( vis ) ) ;

            for ( int j = i ; j <= n ; j ++ )
            {
                if ( vis [ arr [ j ] ] )
                {
                    while ( st.back () != arr [ j ] )
                    {
                        vis [ st.back () ] = 0 ;
                        st.pop_back () ;
                    }
                }
                else
                {
                    vis [ arr [ j ] ] = 1 ;
                    st.push_back ( arr [ j ] ) ;
                }
            }

            for ( int num : st )
            {
                bas [ num ] ++ ;
            }
        }

        for ( pair < int , int > it : bas )
        {
            cout << it.second << " " ;
        }
    }

    return 0 ;
}
